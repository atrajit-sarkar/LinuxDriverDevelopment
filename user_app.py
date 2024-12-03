def main():
    with open('/proc/atrajit_driver') as driver_handle:
        message_from_kernel_space=driver_handle.readline()
    print(message_from_kernel_space)
    return 0

main()


