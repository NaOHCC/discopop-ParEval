FROM ubuntu:jammy
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Etc/UTC
RUN apt update && apt install -y wget python3.10-venv build-essential libboost-all-dev git cmake ninja-build \
    && apt-get clean autoclean && rm -rf /var/lib/apt/lists/{apt,dpkg,cache,log} /tmp/* /var/tmp/*
RUN mkdir -p /root/.local/bin
RUN wget https://github.com/discopop-project/discopop/releases/download/v4.0.1/discopop-4.0.1.deb -O /tmp/discopop-4.0.1.deb && apt install -y /tmp/discopop-4.0.1.deb \
    && rm /tmp/discopop-4.0.1.deb && apt-get clean autoclean && rm -rf /var/lib/apt/lists/{apt,dpkg,cache,log} /tmp/* /var/tmp/*

COPY . /workspace