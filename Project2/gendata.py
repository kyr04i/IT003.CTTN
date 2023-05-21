import random

def gen_data():
    for i in range(10):
        data = "data" + str(i) +'.txt'
        with open(data, 'w') as f:
            for _ in range(10**6):
                f.write(str(random.randint(1, 1000000)) + '\n')
            
gen_data()