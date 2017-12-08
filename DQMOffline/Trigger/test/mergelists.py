#! /usr/bin/env python                                                                                                            

import sys

f1 = open("listcrab_DoubleMuonv1_v2.list")
f1_contents = f1.read()
f1.close()

f2 = open("listcrab_DoubleMuonv2_v2.list")
f2_contents = f2.read()
f2.close()

f3 = open("listcrab_DoubleMuonv3_v2.list")
f3_contents = f3.read()                                                                                                           
f3.close()


f7 = open("listRunC_v2.list", "w") # open in `w` mode to write
f7.write(f1_contents + f2_contents + f3_contents ) # concatenate the contents
f7.close()

