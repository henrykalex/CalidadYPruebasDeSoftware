from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from random import randint


def login():
    # input-username
    # input-password
    # btn btn-primary
    usernameInput = driver.find_element_by_id('input-username')
    usernameInput.send_keys('admin')
    passwordInput = driver.find_element_by_id('input-password')
    passwordInput.send_keys('lol')
    submitInput = driver.find_element_by_class_name('btn-primary')
    submitInput.click()
    return
def addProduct():
    # btn btn-primary
    submitInput = driver.find_element_by_class_name('btn-primary')
    submitInput.click()
    # input-name1
    nameInput = driver.find_element_by_id('input-name1')
    newProductsId.append(randint(0, 9999))
    nameInput.send_keys('Producto nuevo '+str(newProductsId[len(newProductsId)-1]))
    # input-description1
    # nameInput = driver.find_element_by_id('input-description1')
    # nameInput.send_keys('Producto nuevo '+str(randint(0, 9999)))
    # input-meta-title1
    metaTitle1Input = driver.find_element_by_id('input-meta-title1')
    metaTitle1Input.send_keys('Tag'+str(randint(0, 9999)))
    # //*[@id="form-product"]/ul/li[2]/a
    saveProductBotton = driver.find_element_by_xpath('//*[@id="form-product"]/ul/li[2]/a')
    saveProductBotton.click()
    # input-model
    metaTitle1Input = driver.find_element_by_id('input-model')
    metaTitle1Input.send_keys('X'+str(randint(10, 9999)))
    # input-price
    metaTitle1Input = driver.find_element_by_id('input-price')
    metaTitle1Input.send_keys(str(randint(10, 100)))
    # input-quantity
    metaTitle1Input = driver.find_element_by_id('input-quantity')
    metaTitle1Input.send_keys(str(randint(20, 50)))
    # btn-primary
    submitInput = driver.find_element_by_class_name('btn-primary')
    submitInput.click()
    return
def newProducts():
    try:
        WebDriverWait(driver,10).until(EC.text_to_be_present_in_element((By.TAG_NAME,'h1'),'Dashboard'))
    finally:
        # close
        submitInput = driver.find_element_by_class_name('close')
        submitInput.click()
        productsBotton = driver.find_element_by_xpath("//*[@id='menu-catalog']/a")
        productsBotton.click()
        productsBotton = driver.find_element_by_xpath("//*[contains(text(), 'Products')]")
        productsBotton.click()
        productsBotton = driver.find_element_by_xpath("//*[@id='collapse1-1']/li[1]/a")
        productsBotton.click()
        try:
            WebDriverWait(driver,10).until(EC.text_to_be_present_in_element((By.TAG_NAME,'h1'),'Products'))
        finally:
            addProduct()
            addProduct()
            print('----------------------')
            print(newProductsId[0],newProductsId[1])
            # driver.close();
            return
def buyProducts():
    driver.get('http://localhost:4000/')
    try:
        WebDriverWait(driver,10).until(EC.text_to_be_present_in_element((By.TAG_NAME,'h3'),'Featured'))
    finally:
        seacrhInput = driver.find_element_by_class_name('input-lg')
        seacrhInput.send_keys('Producto nuevo '+str(newProductsId[0]))
        # btn-default
        searchButton = driver.find_element_by_class_name('btn-default')
        searchButton.click()
        # //*[@id="content"]/div[3]/div/div/div[1]/a/img
        productBotton = driver.find_element_by_xpath('//*[@id="content"]/div[3]/div/div/div[1]/a/img')
        productBotton.click()
        # button-cart
        submitInput = driver.find_element_by_id('button-cart')
        submitInput.click()
        seacrhInput = driver.find_element_by_class_name('input-lg')
        seacrhInput.clear()
        seacrhInput.send_keys('Producto nuevo '+str(newProductsId[1]))
        # btn-default
        searchButton = driver.find_element_by_class_name('btn-default')
        searchButton.click()
        # //*[@id="content"]/div[3]/div/div/div[1]/a/img
        productBotton = driver.find_element_by_xpath('//*[@id="content"]/div[3]/div/div/div[1]/a/img')
        productBotton.click()
        # button-cart
        submitInput = driver.find_element_by_id('button-cart')
        submitInput.click()
        return
if __name__ == "__main__":
    driver = webdriver.Firefox()
    driver.get('http://localhost:4000/admin')
    newProductsId = []
    login()
    newProducts()
    buyProducts()
