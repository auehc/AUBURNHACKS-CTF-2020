FROM 32bit/ubuntu:16.04

RUN apt update
RUN apt install -y socat 
RUN groupadd ctf

RUN mkdir /pwn

COPY pwn5 /pwn/
COPY flag.txt /pwn/
COPY entry.sh /pwn/

RUN useradd -G ctf --home=/pwn pwnuser
RUN useradd -G ctf --home=/pwn pwnflag

RUN chown pwnflag:pwnflag /pwn/flag.txt
RUN chown pwnflag:pwnflag /pwn/pwn5
RUN chown pwnflag:pwnflag /pwn

RUN chmod 4755 /pwn/pwn5
RUN chmod 444 /pwn/flag.txt
RUN chmod 4755 /pwn/entry.sh



EXPOSE 9004
ENTRYPOINT ["/pwn/entry.sh"]
