FROM alpine
COPY . /code
WORKDIR /code
RUN apk add --update	\
    g++			\
    make		\
  && rm -rf /var/cache/apk/*
RUN make
ENV PATH /code/bin:$PATH
CMD ls bin
