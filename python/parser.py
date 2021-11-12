import csv
import requests
from bs4 import BeautifulSoup as BS
import random
import time
import json
headers ={
    "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36"
}

def get_url (site):
    r = requests.get(site)
    html = BS(r.content, 'html.parser')
    # h=html.select(".content > .rel > table > tbody")
    # j=html.select(".map-listings-list__ListWrapper-sc-1ynfzzj-0 > .map-listings-list__ListItem-sc-1ynfzzj-1")
    # print (j)
    t=[]
    for el in html.select(".map-listings-list__ListWrapper-sc-1ynfzzj-0 > .map-listings-list__ListItem-sc-1ynfzzj-1"):

        # title = el.select('.map-no-border-style___StyledDiv-z3ib6n-1 > a ')
        title = el.find ("div",class_="map-no-border-style___StyledDiv-z3ib6n-1").find("a").get("href")
        t.append(title)
    #print( t )
    with open("item.txt", "w") as file:
        for url in t:
            file.write(f"https://weedmaps.com{url}\n")
    return "suucces"


def get_data(file_p):
    with open(file_p) as file:
        # urls_list= file.readlines()
        #
        # list=[]
        # for url in urls_list :
        #     url= url.strip()
        #     list.append(url)
        urls_list =[ url.strip() for url in file.readlines()]
    # print(urls_list)
    li=[]

    for url in urls_list:
        print(url)
        response=requests.get(url=url,headers=headers)
        soup=BS(response.text,"lxml")
        try:
            item_name=soup.find("div",class_="styled-components__ListingNameWrapper-sc-1sy7kcj-6").find("h1").text.strip()
        except Exception as _ex:
            item_name=None

        try:
            item_number=soup.find("div",class_="src__Box-sc-1sbtrzs-0").find("div",class_="header-info__DesktopButtonContent-sc-1heoxjr-1").text;
        except Exception as _ex:
            item_number=None

        time.sleep(random.randrange(2,10))
        li.append(
            {
                "Name": item_name,
                "Phone" :item_number
            }
        )
        if( item_number==None and item_name==None):
            break
    with open("name_nr.txt", "w") as file:
        json.dump(li,file)

    print(item_name)
# def get_rl (site):
#     # r = requests.get(site)
#     # html = BS(r.content, 'html.parser')
#     # h=html.select(".page-layout")
#     response = requests.get(url=site, headers=headers )
#     soupp= BS(response.text,'lxml')
#     j=soupp.find("div",class_="src__Box-sc-1sbtrzs-0").find("div",class_="header-info__DesktopButtonContent-sc-1heoxjr-1").text
#     # with open("itemmm.txt", "w") as file:
#     #     file.write(f"{soupp[0].text}\n")
#     print (j)
#     # t=[]
#     # for el in html.select(".map-listings-list__ListWrapper-sc-1ynfzzj-0 > .map-listings-list__ListItem-sc-1ynfzzj-1"):
#     #
#     #     # title = el.select('.map-no-border-style___StyledDiv-z3ib6n-1 > a ')
#     #     title = el.find ("div",class_="map-no-border-style___StyledDiv-z3ib6n-1").find("a").get("href")
#     #     t.append(title)
#     # #print( t )
#     # with open("item.txt", "w") as file:
#     #     for url in t:
#     #         file.write(f"https://weedmaps.com{url}\n")

def csvfile ():
    with open("name_nr.txt") as file:
        s=json.load(file)
    # print(type(s))
    # for i in s :
    #     print ("NUme =",i["Name"] ,"pohen =", i["Phone"],"\n")
    with open("nanr.csv", "w") as file:
        writer = csv.writer(file)
        writer.writerow(("NAme","Number"))

    with open("nanr.csv", "a") as file:
        writer=csv.writer(file)
        for i in s :
            writer.writerow(
                [i["Name"], i["Phone"]]
            )




def csvfil ():
    with open("name_nr.txt") as file:
        s=json.load(file)
    # print(type(s))
    # for i in s :
    #     print ("NUme =",i["Name"] ,"pohen =", i["Phone"],"\n")
    # name1="anna"
    # name2="victor"
    # with open("data.csv", "w") as file:
    #     writer = csv.writer(file)
    #     writer.writerow(
    #         [name1,name2]
    #     )
    for i in s:
        print ("n=",i["Name"].strip(" "),"p=",i["Phone"])
    with open("nanr.csv", "w") as file:
        writer = csv.writer(file, delimiter=";")
        writer.writerow( ["Name","Phone number"])
    with open("nanr.csv", "a") as file:
        writer=csv.writer(file, delimiter=";")
        for i in s :
            writer.writerow(
                (i["Name"].strip(" \n"), i["Phone"].strip(" "))
            )


csvfil ()




# print(get_url("https://weedmaps.com/listings/in/germany/bavaria/ansbach"))
#get_data("item.txt")
# get_rl ("https://weedmaps.com/dispensaries/florian-geyer-apotheke")