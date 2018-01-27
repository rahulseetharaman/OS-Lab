# -*- coding: utf-8 -*-
"""
Created on Sat Jan 13 22:48:04 2018

@author: rahul
"""

from Crypto.Hash import SHA256
hash = SHA256.new()
hash.update('message'.encode('UTF-8'))
print(hash.digest())

