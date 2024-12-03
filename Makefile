obj-m += atrajit.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

git_config:
	git config --global user.email "atrajit.sarkar@gmail.com"
	git config --global user.name "atrajit-sarkar"