# Robot Buscador
Proyecto de robótica educativa con sensores y actuadores

## Tutorial MQTT

### Instalaciones

	descargar la signing key o clave de firma utilizando el comando wget
	sudo wget http://repo.mosquitto.org/debian/mosquitto-repo.gpg.key

	Añadimos la clave para a una lista para autenticar el paquete
	sudo apt-key add mosquitto-repo.gpg.key

	Acceder a a la carpeta
	cd /etc/apt/sources.list.d/
	
	descargamos la lista de repositorios (segun version)
	sudo wget http://repo.mosquitto.org/debian/mosquitto-jessie.list
	
	Para ser usuario root
	sudo -i
	
	Actualizamos
	apt-get update
	
	Instalamos el Broken
	apt-get install mosquitto
	
	Instalamos el cliente
	apt-get install mosquitto-clients
	
### Comandos basicos

	mosquitto_sub -h BROKER -t TOPIC
	
#### Ejemplo:
	mosquitto_sub -h localhost -t servidor/publicaciones
	mosquitto_pub -h localhost -t servidor/notificaciones -m "Mensaje desde Putty"
        mosquitto_pub -h localhost -t servidor/notificaciones -m 0
