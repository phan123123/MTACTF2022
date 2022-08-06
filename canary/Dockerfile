FROM i386/ubuntu

MAINTAINER phanNT
RUN apt-get update

RUN useradd -m canary

COPY ./share/flag /flag
COPY ./share/run.sh /home/canary/run.sh
COPY ./share/canary /home/canary/canary

RUN chmod +x /home/canary/run.sh

RUN chown -R root:canary /home/canary
RUN chmod -R 755 /home/canary
RUN chmod 644 /flag

RUN echo canary > /etc/cron.deny
RUN chmod 644 /etc/cron.deny

RUN chmod -R 774 /var/tmp
RUN chmod -R 774 /tmp
RUN chmod -R 774 /dev
RUN chmod -R 774 /run
RUN chmod 1733 /dev/shm

WORKDIR /home/canary
 
CMD ["./run.sh"]

EXPOSE 1337
