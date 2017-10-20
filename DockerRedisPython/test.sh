docker run -d --name redis -p 6379:6379 redis:latest

docker build -t alpine:webapp .
docker run -d --name webapp -p 4000:80 --link redis alpine:webapp

#----------------------------------------------------------------------

docker-compose up -d #levantar  conjunto de servicios

docker-compose down #bajar  conjunto de servicios
