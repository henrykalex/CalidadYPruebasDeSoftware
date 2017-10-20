from selenium import webdriver
from selenium.webdriver.common.by import By

def get_users():
    driver = webdriver.Firefox()

    driver.get('http://micampus.csf.itesm.mx/index.php/division-de-diseno-ingenieria-y-arquitectura/directorio')

    selector = driver.find_elements(By.CSS_SELECTOR,'td')
    print(len(selector))
    count = 0
    arrayCount = 0;
    names = []
    emails = []
    usersT = []
    for sel in selector:
        count += 1;
        if(count == 1):
            # print('Td '+sel.tag_name)
            name = sel.text.split('\n')[0]
            print(name)
            names.append(name)
        elif(count == 4):
            # print('Td '+sel.tag_name)
            email = sel.text.split('\n')[0]
            print(email)
            emails.append(email)
            count = 0
            usersT.append([name,email])


    print('----------------------')
    driver.close();
    return [names,emails,usersT]
if __name__ == "__main__":
    get_users()
