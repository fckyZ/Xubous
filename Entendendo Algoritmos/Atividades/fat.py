def fat ( num ):
    if num == 0 or num == 1:
        return 1
    else:
        return num * fat (num - 1);

print ( fat () )