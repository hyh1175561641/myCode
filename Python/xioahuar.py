#爬虫练习，代码已失效


#!/usr/bin/env python
# -*- coding:utf-8 -*-
from urllib import request
from bs4 import BeautifulSoup
import re
import time
import gevent
from gevent import monkey
monkey.patch_all()

def parser(html):
    try:
        soup = BeautifulSoup(html, 'html.parser', from_encoding='gbk')
        imgs = soup.find_all('img', src=re.compile(r'/d/file/\d+/\w+\.jpg'))
        return imgs
    except Exception as e:
        print('in parser error=%s' % e)
        return None

def save_img(path, data):
    try:
        with open(path, 'wb') as f:
            f.write(data)
    except Exception as e:
        print('in save_img error=%s' % e)

def download(url):
    header = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 Safari/537.36'
    }
    try:
        req = request.Request(url=url, headers=header)
        response = request.urlopen(req, timeout=10)
        return response.read()
    except Exception as e:
        print('in download error=%s' % e)

def spider():
    first_url = "http://www.xiaohuar.com/list-1-%s.html"
    imgs = []
    for i in range(10):
        html = download(first_url%i)
        if html:
            temp = parser(html)
        if temp !=[]:
            imgs += temp

    s_time = time.time()
    glist = []
    if imgs != []:
        for img in imgs:
            data = download("http://www.xiaohuar.com%s" % img['src'])
            g = gevent.spawn(save_img,'%s.jpg' % img['alt'], data)
            glist.append(g)
        gevent.joinall(glist)
        e_time = time.time()
        print('耗费%s秒' % (e_time-s_time))
    else:
        print('网络错误')

if __name__ == '__main__':
    spider()
    
