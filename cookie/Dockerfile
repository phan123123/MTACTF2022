FROM i386/ubuntu

MAINTAINER phanNT
RUN apt-get update

RUN useradd -m cookie

COPY ./share/flag /flag
COPY ./share/run.sh /home/cookie/run.sh
COPY ./share/cookie /home/cookie/cookie

RUN chmod +x /home/cookie/run.sh

RUN chown -R root:cookie /home/cookie
RUN chmod -R 755 /home/cookie
RUN chmod 644 /flag

RUN echo cookie > /etc/cron.deny
RUN chmod 644 /etc/cron.deny

RUN chmod -R 774 /var/tmp
RUN chmod -R 774 /tmp
RUN chmod -R 774 /dev
RUN chmod -R 774 /run
RUN chmod 1733 /dev/shm

WORKDIR /home/cookie
 
CMD ["./run.sh"]

EXPOSE 1337
