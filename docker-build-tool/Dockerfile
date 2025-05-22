FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive
ENV PYTHON_VERSION=3.12.3


RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    ca-certificates \
    libssl-dev \
    zlib1g-dev \
    libbz2-dev \
    libreadline-dev \
    libsqlite3-dev \
    libncursesw5-dev \
    libgdbm-dev \
    libnss3-dev \
    liblzma-dev \
    tk-dev \
    libffi-dev \
    uuid-dev \
    xz-utils \
    && apt-get clean

# Install Python 3.12 from source
RUN cd /usr/src && \
    wget https://www.python.org/ftp/python/${PYTHON_VERSION}/Python-${PYTHON_VERSION}.tgz && \
    tar xzf Python-${PYTHON_VERSION}.tgz && \
    cd Python-${PYTHON_VERSION} && \
    ./configure --enable-optimizations && \
    make -j$(nproc) && \
    make altinstall && \
    ln -s /usr/local/bin/python3.12 /usr/bin/python3 && \
    ln -s /usr/local/bin/pip3.12 /usr/bin/pip3

# Default to a working directory (you can clone your repo here)
WORKDIR /workspace


RUN git clone --recurse-submodules https://github.com/OpenGate-RB3/Open-Gate-MQTT-Client.git target
# Run the build script twice to work around Paho alias bug
RUN cd target && ./build.sh || true && ./build.sh

CMD [ "bash" ]