import pyupbit
import os
import jwt
import uuid
import hashlib
from urllib.parse import urlencode
import backtrader as bt
import pandas as pd

import json

from pprint import pprint

import requests

select_cmd = input("매수 = 1, 매도 = 2")

access_key = 'Hz8XXR4dc6NEGTLoCUGxtHerbr1nZF1uSX3NFPMB'
secret_key = 'vT9tjTOsT1xjylkLwHbh7fxqRVDcQzrxCXMOkSOW'
server_url = 'https://api.upbit.com'

payload = {
    'access_key': access_key,
    'nonce': str(uuid.uuid4()),
}

jwt_token = jwt.encode(payload, secret_key)
authorize_token = 'Bearer {}'.format(jwt_token)
headers = {"Authorization": authorize_token}

res = requests.get(server_url + "/v1/accounts", headers=headers)

d = res.json()

def coin_list():
    print("매수 가능한 코인의 목록입니다")

    url = "https://api.upbit.com/v1/market/all"

    querystring = {"isDetails": "false"}

    headers = {"Accept": "application/json"}

    response = requests.request("GET", url, headers=headers, params=querystring)

    df = pd.DataFrame(response.json())

    for i in range(len(response.json())):
        query = {"market": df.iloc[i][0], "count": "200"}

        query_string = urlencode(query).encode()

        m = hashlib.sha512()
        m.update(query_string)
        query_hash = m.hexdigest()

        payload = {
            'access_key': access_key,
            'nonce': str(uuid.uuid4()),
            'query_hash': query_hash,
            'query_hash_alg': 'SHA512',
        }

        jwt_token = jwt.encode(payload, secret_key)
        authorize_token = 'Bearer {}'.format(jwt_token)
        headers = {"Authorization": authorize_token}

        res = requests.get(server_url + "/v1/orders/chance", params=query, headers=headers)

        # pprint(res.json())
        k = res.json()
        print(k.get("market").get("id"))
        # for j in range(len(k)):
        #     print(k[i]['id'])


if int(select_cmd) == 1:


    coin_list()

    select_coin = input("매수할 코인의 마켓 id를 입력하세요")
    percent_buy = input("매수할 %를 입력하세요")

    if d[0]['unit_currency'] == 'KRW':
        a = float(d[0]['balance'])
        pay_amt = a * (float(percent_buy) * .01)

    upbit = pyupbit.Upbit(access_key, secret_key)
    pprint(upbit.buy_market_order(select_coin, pay_amt))  # 시장가 매수

if int(select_cmd) == 2:

    for i in range(len(d)):
        print(d[i]['unit_currency'] + "-" + d[i]['currency'])

    select_coin = input("매도할 코인을 입력하세요")

    unit_cur = select_coin.split('-')

    percent_sell = input("매도할 %를 입력하세요")

    for i in range(len(d)):
        if d[i]['currency'] == unit_cur[1]:
            b = float(d[i]['balance'])
            coin_amt = b * (float(percent_sell) * .01)
            print(coin_amt)
            upbit = pyupbit.Upbit(access_key, secret_key)
            pprint(upbit.sell_market_order(select_coin, coin_amt))  # 시장가 매도

# print(upbit.buy_market_order("KRW-DOGE", pay_amt)) #시장가 매수
# print(upbit.sell_market_order("select_coin", coin_amt)) # 시장가 매도
