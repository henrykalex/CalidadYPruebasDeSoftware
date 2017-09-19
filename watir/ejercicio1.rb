require 'watir'
browser = Watir::Browser.new :firefox

browser.goto 'http://blazedemo.com'

opciones = browser.select_list(:name => "fromPort").options
cont = 0
opciones.each do |op|
    if (cont  == 2)
      op.select
    end
    cont += 1
end

opciones = browser.select_list(:name => "toPort").options
cont = 0
opciones.each do |op|
    if (cont  == 3)
      op.select
    end
    cont += 1
end

browser.button(:class => "btn").click

sleep(1)

browser.buttons(:class => "btn").last.click

sleep(1)


browser.text_field(:id => "inputName").set("Enrique M")
browser.text_field(:id => "address").set("Carlos lazo")
browser.text_field(:id => "city").set("Ciudad MX")
browser.text_field(:id => "state").set("TX")
browser.text_field(:id => "zipCode").set("02638")
opciones = browser.select_list(:id => "cardType").options[1].select
browser.text_field(:id => "creditCardNumber").set("567856783579")
browser.text_field(:id => "creditCardMonth").set("11")
browser.text_field(:id => "creditCardYear").set("2017")
browser.text_field(:id => "nameOnCard").set("Enrique Mondragon")
browser.checkbox(:id => "rememberMe").set

browser.button(:class => "btn").click
