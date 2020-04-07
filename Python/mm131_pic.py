#爬虫练习


#!/usr/bin/env python3
#-*- coding:utf-8 -*-
"""
#!usr/bin/env python3
2016/10/2
"""

import requests
import bs4
from urllib.parse import urljoin

headers={"connection":"keep-alive",
        "upgrader-insecure-requests":"1",
        "user-agent":"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36",
        "Accept-Encoding":"gzip,deflate,sdch,br",
        "Accept-Language":"zh-CN,zh"}

def this_img_url(bs4_obj):
    tag=bs4_obj.find("div",class_="content-pic")
    if not tag:
        return
    else:
        return tag.a.img["src"]


def next_img_url(bs4_obj):
    tags=bs4_obj.find_all("a",class_="page-ch")
#     if not tags:
#         print("1")
#         tags=bs4_obj.find_all("a",class_="updown-r")
#         if not tags:
#             print("没有下一篇了，需要修改其实url")
#         else:
#             return tags["href"]
#     else:
    for tag in tags:
        #显示的时候出现乱码，就用乱码即可
        if tag.string=="ÏÂÒ»Ò³":
            return tag["href"]
    else:
        print("没有下一页了，正在跳转到下一篇")
        tags=bs4_obj.find_all("a",class_="updown_r")
        if not tags:
            print("没有下一篇了，需要修改其实url")
            return
        else:
            return tags[0]["href"]

def save_img(img_url, name):
    with open("./%s.jpg" % name, "wb") as jpg:
        jpg.write(requests.get(img_url,headers=headers,stream=True).raw.read())


def full_img_url(root_url, join_url):
    return urljoin(root_url,join_url)


init_url="http://www.mm131.com/xinggan/2386.html"
total_num=input("请输入图片数目：")
full_url=init_url
html=requests.get(full_url,headers=headers)
bs4_obj=bs4.BeautifulSoup(html.text,"html.parser")

for i in range(0,int(total_num)+1):
    print(full_url)
    this_url=this_img_url(bs4_obj)
    save_img(this_url, i)
    next_url=next_img_url(bs4_obj)
    full_url=full_img_url(init_url,next_url)
    html=requests.get(full_url,headers=headers)
    bs4_obj=bs4.BeautifulSoup(html.text,"html.parser")
    
print("done")
