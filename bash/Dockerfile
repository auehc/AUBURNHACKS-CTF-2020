FROM ubuntu:latest
 
RUN apt-get update && apt-get install -y openssh-server unzip
RUN mkdir /var/run/sshd
RUN echo 'root:auehc' | chpasswd

RUN useradd level1
RUN useradd level2
RUN useradd level3
RUN useradd level4
RUN useradd level5

RUN echo "level1:aubie" | chpasswd
RUN echo "level2:aubie{1_l1k3_b45h}" | chpasswd 
RUN echo "level3:aubie{gR3p_i5_G00d}" | chpasswd 
RUN echo "level4:aubie{s0_m4Ny_c0Mpr3s510nS}" | chpasswd
RUN echo "level5:aubie{7h4Nk_g00dN35s_u_f0UnD_m1}" | chpasswd

COPY level1 /home/level1/README
RUN chown level1 /home/level1/README
RUN chmod 400 /home/level1/README

COPY level2 /home/level2/solong...
RUN chown level2 /home/level2/solong...
RUN chmod 400 /home/level2/solong...

COPY level3 /home/level3/compressed
RUN chown level3 /home/level3/compressed
RUN chmod 400 /home/level3/compressed

COPY level4 /home/.hidden
RUN chown level4 /home/.hidden
RUN chmod 400 /home/.hidden

COPY level5/ /home/level5/all_the_files
RUN chown level5 /home/level5/all_the_files
RUN chmod 400 /home/level5/all_the_files

RUN echo "exit" >> .bashrc

EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
