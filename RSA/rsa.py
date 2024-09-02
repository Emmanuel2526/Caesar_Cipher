# Author: Osalotioman
# Program: RSA Encryption Program
def dd(v):
 if len(str(v)) < 2: return "0"+str(v);
 else: return str(v);
def p(b, e, m):
 v = 1
 for _ in range(e): v=v*b%m;
 return v
emb = [*map(int, input("Enter public keys (e m), to specify block length(<m) format (e m b): ").split())]
e=emb[0]
m=emb[1]
pt = [*map(str, input("Enter plainText: ").lower().split())]
al = "abcdefghijklmnopqrstuvwxyz"
ca = {}
for _ in range(1, 27): ca[al[_-1]] = dd(_);
for _ in range(10): ca[str(_)] = str(_);
r = ""
try:
 b=emb[2]
 pt1 = "".join(pt)
 c1 = ""
 for i in pt1: c1+=ca[i];
 pt = []
 v1 = ""
 for _ in range(len(c1)):
  if _%b == 0 and _>0:
   pt.append(v1)
   v1 = ""
  v1 += c1[_] 
 if v1 != "":
  pt.append(v1) 
  #while len(v1) < b: v1 += "x";
  #pt.append(v1)
except:
 pass
print(pt)
for v in pt:
 c = ""
 for i in v: c+=ca[i];
 c = int(c)
 c = p(c, e, m)
 r += str(c)+" "
print(r)
# print(pt)
# print(ca)
