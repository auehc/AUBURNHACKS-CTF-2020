FROM ubuntu

RUN apt update
RUN apt install -y socat 
RUN apt install -y default-jre
RUN groupadd ctf



COPY rev4.class /
COPY flag.txt  /
COPY entry.sh /

RUN useradd -G ctf --home=/ revuser
RUN useradd -G ctf --home=/ revflag

RUN chown revflag:revflag /flag.txt
RUN chown revflag:revflag /rev4.class

RUN chmod 4755 /rev4.class
RUN chmod 444 /flag.txt
RUN chmod 4755 /entry.sh

EXPOSE 9023
ENTRYPOINT ["/entry.sh"]
