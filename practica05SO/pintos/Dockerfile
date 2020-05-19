FROM ubuntu:16.04

# Install set up tools
RUN apt-get update && \
    DEBIAN_FRONTEND=noninterative \
        apt-get install -y --no-install-recommends \
            curl


# Prepare the Pintos directory
RUN mkdir /pintos
WORKDIR /pintos

# Install useful user programs
RUN apt-get update && \
    DEBIAN_FRONTEND=noninterative \
        apt-get install -y --no-install-recommends \
            coreutils \
	    manpages-dev \
            xorg openbox \
            ncurses-dev \
            gcc clang make \
            gdb ddd \
            qemu

# Clean up apt-get's files
RUN apt-get clean autoclean && \
    rm -rf /var/lib/apt/* /var/lib/cache/* /var/lib/log/*

# Add Pintos to PATH
ENV PATH=/pintos/src/utils:$PATH


CMD ["sleep", "infinity"]