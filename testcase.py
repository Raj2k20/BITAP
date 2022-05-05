import abc
import random
def dataset(a,b):
        f = open(b, "w+")
        for i in range(0,(a)):
            string = "atcg"
            c = random.choice(string)
            f.write(c)
        f.close()


i = dataset(10,"file1.txt")
j = dataset(5,"file2.txt")
