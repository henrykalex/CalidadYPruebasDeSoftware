from selenium import webdriver

driver = webdriver.Firefox()
driver.get('http://nitrowriters.com/form/form.html')

txt = driver.find_element_by_id('my_text_field')
txt.send_keys('Este es un primer ejemplo')

from selenium.webdriver.common.by import By
txt = driver.find_element(By.ID,'my_text_field')
txt.send_keys('Concatena esto')

descriptions = driver.find_elements(By.CLASS_NAME,'description') # Todos los elementos
for desc in descriptions:
    print(desc.text)

textarea = driver.find_element(By.TAG_NAME,'textarea') # El primer elemento que encuentre
textarea.send_keys('Relleno de el area de texto :D')

link = driver.find_element(By.LINK_TEXT, 'Go to SitePoint')
print(link.text)
# link.click()

inputs = driver.find_elements(By.TAG_NAME, 'input')
for input in inputs:
    if input.get_attribute('type') == 'text':
        input.send_keys('el mismo texto en Todos lados')

# css selectors
# * Selector
selector = driver.find_element(By.CSS_SELECTOR,'*')
print('Selector *:')
print(selector.text)
print('----------------------')

# p Selector (Grouping type)
selector = driver.find_elements(By.CSS_SELECTOR,'h2,p')
for sel in selector:
    print('Selector '+sel.tag_name)
    print(sel.text)
print('----------------------')

# form div h2 Selector (Descendent)
selector = driver.find_element(By.CSS_SELECTOR,'form div h2')
print('Selector form div h2:')
print(selector.text)
print('----------------------')

# form > div h2 Selector (Direct Child)
selector = driver.find_element(By.CSS_SELECTOR,'form > div h2')
print('Selector form > div h2:')
print(selector.text)
print('----------------------')

# h2 + * Selector (Adjacent Sibling)
selector = driver.find_element(By.CSS_SELECTOR,'h2 + *')
print('Selector h2 + *')
print(selector.text)
print('----------------------')

# h2 ~ * Selector (General Sibling)
selector = driver.find_elements(By.CSS_SELECTOR,'.checkbox ~ *')
print('Selector checkbox ~ *')
for sel in selector:
    print(sel.text)
print('----------------------')

# .button_text Selector (Class)
selector = driver.find_element(By.CSS_SELECTOR,'.button_text')
print('Selector .button_text')
print(selector.tag_name)
print('----------------------')

# #li_15 Selector (ID)
selector = driver.find_element(By.CSS_SELECTOR,'#li_15')
print('Selector #li_15')
print(selector.tag_name)
print('----------------------')

# :link Selector (ID)
selector = driver.find_elements(By.CSS_SELECTOR,':link')
print('Selector :link')
for sel in selector:
    print(sel.tag_name,sel.text)
print('----------------------')

# ul li:first-child Selector (ID)
selector = driver.find_elements(By.CSS_SELECTOR,'ul li:first-child')
print('Selector ul li:first-child')
for sel in selector:
    print(sel.tag_name,sel.text)
print('----------------------')
