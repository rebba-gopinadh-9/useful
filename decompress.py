def isNum(k):
    if k in "abcdefghijklmnopqrstuvwxyz" or k=="[" or k=="]":
        return False
    return True
def isAlpha(k):
    if k in "abcdefghijklmnopqrstuvwxyz":
        return True
    else:
        return False
def nextInt(s,st,en):
    t=""
    i=st
    while isNum(s[i]) and i<en:
        t=t+s[i]
        i=i+1
    return i,int(t)

def findNext(s,st,en):
    count=0
    i=st
    while (i<en):
        if s[i]=="[":
            count=count+1
        if s[i]=="]":
            count=count-1
        if count==0:
            return i
        i+=1

def f(s,st,en):
    i=st
    e=""
    while i< en :
        if isAlpha(s[i]):
            e=e+s[i]
        if isNum(s[i]):
            t=0
            j=i
            while isNum(s[j]):
                t=t*10+int(s[i])
                j=j+1
            i=j-1
            p=findNext(s,i+1,en)
            e=e+t*f(s,i+1,p)
            i=p
        i=i+1
    return e

s="15[11[a]b]40[c]"
print(f(s,0,len(s)))
