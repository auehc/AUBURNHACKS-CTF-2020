FROM 32bit/ubuntu:16.04

RUN apt update
RUN apt install -y socat 
RUN groupadd ctf

RUN mkdir /pwn

COPY pwn4 /pwn/
COPY flag.txt /pwn/
COPY entry.sh /pwn/

RUN useradd -G ctf --home=/pwn pwnuser
RUN useradd -G ctf --home=/pwn pwnflag

RUN chown pwnflag:pwnflag /pwn/flag.txt
RUN chown pwnflag:pwnflag /pwn/pwn4
RUN chown pwnflag:pwnflag /pwn

RUN chmod 4755 /pwn/pwn4
RUN chmod 444 /pwn/flag.txt
RUN chmod 4755 /pwn/entry.sh



EXPOSE 9003
ENTRYPOINT ["/pwn/entry.sh"]
