FROM 32bit/ubuntu:16.04

RUN apt update
RUN apt install -y socat 
RUN groupadd ctf

RUN mkdir /rev

COPY rev2 /rev/
COPY flag_1.txt /rev/
COPY flag_2.txt /rev/
COPY entry.sh /rev/entry.sh

RUN useradd -G ctf --home=/rev revuser
RUN useradd -G ctf --home=/rev revflag

RUN chown revflag:revflag /rev/flag_1.txt
RUN chown revflag:revflag /rev/flag_2.txt
RUN chown revflag:revflag /rev/rev2
RUN chown revflag:revflag /rev

RUN chmod 4755 /rev/rev2
RUN chmod 444 /rev/flag_1.txt
RUN chmod 444 /rev/flag_2.txt
RUN chmod 4755 /rev/entry.sh

EXPOSE 9021
ENTRYPOINT ["/rev/entry.sh"]
