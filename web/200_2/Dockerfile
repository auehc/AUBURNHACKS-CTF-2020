FROM ubuntu:latest

env DEBIAN_FRONTEND="noninteractive"

RUN apt-get -y update && apt-get install -y apache2 apache2-doc apache2-utils mysql-server php libapache2-mod-php php-mysql

COPY index.html /var/www/html
COPY login.php /var/www/html
COPY db.sh /db.sh
COPY logos /var/www/html

env APACHE_RUN_USER www-data
env APACHE_RUN_GROUP www-data
env APACHE_PID_FILE /var/run/apache2.pid
env APACHE_RUN_DIR /var/run/apache2
env APACHE_LOCK_DIR /var/lock/apache2
env APACHE_LOG_DIR /var/log/apache2

RUN chmod 700 /db.sh && chmod 755 /var/www/html && chmod 755 /var/www/html/*

EXPOSE 80

ENTRYPOINT ["sh","/db.sh"]