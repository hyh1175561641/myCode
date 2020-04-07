#爬虫练习

import urllib,urllib2
import re
import os 

def main(url,total):
	head = url[0:31]
	end = url[31:-5]
	if not os.path.exists("./pic/%s_%s"%(end,total)):os.makedirs("./pic/%s_%s"%(end,total))
	for x in xrange(9,total+1):
		html = urllib2.urlopen(url).read()
		image = re.compile(r"""class="down-btn" href='(.+?\.jpg)'""")
		imglist = re.findall(image,html)
		print x,end
		urllib.urlretrieve(imglist[0] , './pic/%s_%s/%s_%s.jpg' % (end,total,end,x))
		url = head+"%s_%s.html" % (end,(x+1))

url='http://www.mmonly.cc/mmtp/xgmn/131197.html'
total = 43
if not os.path.exists("./pic/"):os.makedirs("./pic/")
main(url,total)