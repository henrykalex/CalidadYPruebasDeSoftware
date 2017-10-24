from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
# http://seleniumhq.github.io/selenium/docs/api/java/org/openqa/selenium/WebElement.html
# http://seleniumhq.github.io/selenium/docs/api/java/org/openqa/selenium/support/ui/WebDriverWait.html
# http://selenium-python.readthedocs.io/api.html
# https://seleniumhq.github.io/selenium/docs/api/py/api.html#
# https://seleniumhq.github.io/selenium/docs/api/py/webdriver_support/selenium.webdriver.support.expected_conditions.html?highlight=expected
import time
import unicodedata

import practica

from random import randint


def register_users(usersT):
    driver = webdriver.Firefox()
    # driver.get('http://blazedemo.com/register')
    for index, user in enumerate(usersT):
        driver.get('http://blazedemo.com/register')
        print(user)
        nameInput = driver.find_element_by_id('name')
        nameInput.send_keys(user[0])
        companyInput = driver.find_element_by_id('company')
        companyInput.send_keys('ITUSM')
        emailInput = driver.find_element_by_id('email')
        email = user[1]+str(randint(0, 9999))
        user[1] = email
        emailInput.send_keys(email)
        passswordInput = driver.find_element_by_id('password')
        passw = user[0].replace(" ","").lower()
        passw.encode("ascii", "ignore").decode("utf-8")
        print(passw)
        passswordInput.send_keys(passw)
        passswordInput = driver.find_element_by_id('password-confirm')
        passswordInput.send_keys(passw)
        user.append(passw);

        submitInput = driver.find_element_by_class_name('btn')
        submitInput.click()

        try:
            WebDriverWait(driver,10).until(EC.text_to_be_present_in_element((By.CLASS_NAME,'panel-body'),'You are logged in!'))
        finally:
            # driver.close()
            driver.get('http://blazedemo.com')
            select = driver.find_elements(By.TAG_NAME,'option')
            print(index)
            driver.find_element_by_xpath("//select[@name='fromPort']/option["+str(index+1)+"]").click() # text()='Rome'
            driver.find_element_by_xpath("//select[@name='toPort']/option["+str(index+1)+"]").click() # text()='Rome'
            submitInput = driver.find_element_by_class_name('btn-primary')
            submitInput.click()

            try:
                WebDriverWait(driver,10).until(EC.text_to_be_present_in_element((By.TAG_NAME,'th'),'Choose'))
            finally:
                submitInput = driver.find_elements_by_class_name('btn')
                submitInput[2].click()
                try:
                    WebDriverWait(driver,10).until(EC.text_to_be_present_in_element((By.TAG_NAME,'label'),'Name'))
                finally:
                    inputText = driver.find_element_by_id('inputName')
                    inputText.send_keys(user[0])
                    inputText = driver.find_element_by_id('address')
                    inputText.send_keys('Carlos lazo 100')
                    inputText = driver.find_element_by_id('city')
                    inputText.send_keys('México')
                    inputText = driver.find_element_by_id('zipCode')
                    inputText.send_keys('02310')
                    inputText = driver.find_element_by_id('creditCardNumber')
                    inputText.send_keys('5566778899886644')
                    inputText = driver.find_element_by_id('creditCardMonth')
                    inputText.send_keys("11")
                    inputText = driver.find_element_by_id('creditCardYear')
                    inputText.send_keys("20")
                    inputText = driver.find_element_by_id('nameOnCard')
                    inputText.send_keys(user[0])
                    inputText = driver.find_element_by_id('rememberMe')
                    inputText.click()
                    submitInput = driver.find_element_by_class_name('btn-primary')
                    submitInput.click()
                    try:
                        # Thank you for your purchase today!
                        WebDriverWait(driver,10).until(EC.text_to_be_present_in_element((By.TAG_NAME,'h1'),'Thank you for your purchase today!'))
                    finally:
                        driver.get('http://blazedemo.com/home')
                        # dropdown
                        dropBtn = driver.find_element_by_xpath("//*[@class='dropdown']/a") # text()='Rome'
                        print(dropBtn)
                        dropBtn.click()
                        # dropdown-menu
                        logoutBtn = driver.find_element_by_xpath("//*[@class='dropdown-menu']/li/a") # text()='Rome'
                        print(logoutBtn)
                        logoutBtn.click()
                        try:
                            WebDriverWait(driver,10).until(EC.text_to_be_present_in_element((By.TAG_NAME,'h1'),'Welcome to the Simple Travel Agency!'))
                        finally:
                            if index == 6:
                                break



        # from selenium.webdriver·support.ui import Select
        # select = Select(sriver.find_element_by_id('usage'))
        # select.select_by_value('4')
    # driver.close()
    # print(usersT)
    return

if __name__ == '__main__':
    [users,emails,usersT] = practica.get_users()
    register_users(usersT)

# http://blazedemo.com/register
