
def check(s):
    for c in s:
        if c >= '0' and c <= '9': continue
        elif c >= 'a' and c <= 'z': continue
        elif c >= 'A' and c <= 'Z': continue
        else: return False
    return True

# Driver function 
if __name__=="__main__":

    with open("stackcontents", "r") as f:
        lst = f.readlines()
        lst = [x.strip() for x in lst]
        lst = ['0'*(8-len(x))+x for x in lst]
        lst = [ ''.join([chr(int(x[2*i:2*i+2], 16)) for i in range(4)])[::-1] for x in lst]
        s = ''.join(lst)
        for i in range(len(s)-30+1):
            if check(s[i:i+30]):
                print(s[i:i+30])
        # print(s)