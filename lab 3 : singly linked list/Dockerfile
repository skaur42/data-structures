FROM alpine:3.12

RUN apk update && \
    apk upgrade && \
    apk add --no-cache build-base gdb \
        valgrind git openssh less

ENV CC=gcc
ENV CXX=g++
