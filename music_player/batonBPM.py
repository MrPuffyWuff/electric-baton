f=open("batonTime.txt")
x = f.read()
y = x.split()
for i in range(len(y)):
    y[i]=float(y[i])
f2 = open("batonAbsAccel.txt")
a=f2.read()
b = a.split()
for i in range(len(b)):
    b[i] = float(b[i])
TvsA = dict(zip(b,y))

def findBeats(b, TvsA):
    ts = []
    for i in range(len(b)-1):
        if b[i]>0 and b[i+1]<0:
            t1 = TvsA[b[i]]
            t2 = TvsA[b[i+1]]
            t = ((t2-t1)/2.00)
            ts.append(t+t1)
    return ts



def main():
    ts = findBeats(b, TvsA)
    print(ts)

if __name__ == "__main__":
    main()