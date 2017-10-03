from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Firefox()

driver.get('http://micampus.csf.itesm.mx/index.php/division-de-diseno-ingenieria-y-arquitectura/directorio')

selector = driver.find_elements(By.CSS_SELECTOR,'td')
print(len(selector))
count = 0;
names = []
emails = []
for sel in selector:
    count += 1;
    if(count == 1):
        print('Td '+sel.tag_name)
        print(sel.text.split('\n')[0])
        names.append(sel.text.split('\n')[0]))
    elif(count == 4):
        print('Td '+sel.tag_name)
        print(sel.text.split('\n')[0])
        emails.append(sel.text.split('\n')[0]))
        count = 0

print('----------------------')
