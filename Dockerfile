FROM debian:buster

RUN echo "- Updating Debian"
RUN apt-get update && apt-get upgrade -y

RUN echo "- Installing dependencies"
RUN apt install -y \
	gcc \
	ccache \
	cppcheck \
	doxygen \
	git \
	make \
	tar \
	unzip \
	cmake \
	libgtkmm-3.0 \
	libgtkmm-3.0-dev \
	libmariadb-dev

RUN echo "- Building the project"
RUN git clone https://github.com/cpwonline/project-name.git
RUN cd project-name && mkdir build && cd build
RUN cmake .. && cmake --build . && cmake --build . --target install

CMD /usr/local/bin/project-name