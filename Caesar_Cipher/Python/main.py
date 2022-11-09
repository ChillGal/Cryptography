def cipher(string, offset):
    alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                'u', 'v', 'w', 'x', 'y', 'z']
    string = list(string)
    offset = int(offset)
    for i in range(len(string)):
        if string[i] == ' ':
            continue
        for j in range(len(alphabet)):
            if string[i] == alphabet[j]:
                if j + offset > 26:
                    string[i] = alphabet[j + offset - 26]
                    break
                else:
                    string[i] = alphabet[j + offset]
                    break
            elif string[i] == alphabet[j].upper():
                if j + offset > 26:
                    string[i] = alphabet[j + offset - 26].upper()
                    break
                else:
                    string[i] = alphabet[j + offset].upper()
                    break
    return ''.join(string)


if __name__ == '__main__':
    print('Caesar Cipher generator')
    enc_type = input('Encrypt or Decrypt? (d/e):').lower()
    if enc_type == 'd':
        answer = input('Enter phrase:')
        cipher_offset = input('Enter the cipher offset(0-25):')
        cipher_offset = 26 - int(cipher_offset)
        print('The decrypted phrase is ' + cipher(answer, cipher_offset))
    elif enc_type == 'e':
        answer = input('Enter phrase:')
        cipher_offset = input('Enter the cipher offset(0-25):')
        print('The encrypted phrase is ' + cipher(answer, cipher_offset))
    else:
        print('Not valid input')
    input('Press Enter to close...')
