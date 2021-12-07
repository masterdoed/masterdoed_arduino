import matplotlib.pyplot as plt
import csv
import pandas


# CSV Data Format: DateTime,temp,humidity
# temp: key value
# humidity: key value
# Good Sample:  2021-12-07 16:17:14,dht11_temp=23.0000000000,dht11_humidity=39.0000000000
# Bad Sample:   2021-11-15 12:57:26,Time out error
#               2021-11-15 12:57:26,dht11_temp=0.0000000000,dht11_humidity=0.0000000000





def readCSV (path):
    errorCount=0
    with open(path, 'r') as file:
        myCSV=csv.reader(file)
        for row in myCSV:
            if "=0.0" in str(row[1]):
                errorCount+=1
            else:
                #DateTime
                print(row[0])
                
                #extract temp from row
                rowSplit=row[1].split("=")
                temp=rowSplit[1]
                
                #extract humidity from row
                rowSplit=row[2].split("=")
                humidity=rowSplit[1]
    
    print(errorCount)





def plot ():
    plt.plot([1, 2, 3, 4])
    plt.ylabel('some numbers')
    #plt.savefig('foo.png')
    plt.show()

def main():
    readCSV("wohnzimmer.csv")
    

if __name__ == "__main__":
    main()