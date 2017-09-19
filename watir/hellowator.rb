require 'watir'
browser = Watir::Browser.new :firefox

browser.goto 'http://nitrowriters.com/form/form.html'

# buscar el atributo id "my_text_field"
browser.text_field(:id => "my_text_field").set("hola")
browser.textarea(:id => "a_text_area").set("hola")
puts(browser.inspect);

# Set a radiobutton
browser.radio(:id => "familiar_rails_3").set

# Set all checkboxes
checks = browser.checkboxes(:name => /element_14/)
checks.each do |check|
    check.set
  end

# contar el numero de elementos select
puts browser.select_list(:id => "usage").options.count

# Seleccionar la tercera opcion
opciones = browser.select_list(:id => "usage").options

puts(opciones.inspect)

opciones.last.select

opciones[2].select

# cont = 0
# opciones.each do |op|
#     if (cont  == 3)
#       op.select
#     end
#     cont += 1
# end
# browser.select_list(:id => "usage").options(:index => 3).select
