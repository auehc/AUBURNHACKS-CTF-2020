#flip the bits of a given plaintext value
##We'll say that the plaintext is hex, or rather the hex equivalent to an ascii word
##Convert the hex value into binary
## for each character in the provided binary, flip the bits
##

import binascii

##ENCRYPTING SECTION:
#1 convert word into hex value:
#2 convert hex values into binary
#3 flip each binary value 
#4 convert binary to decimal
#5 xor with the key
#6 convert decimal to hex

##DECRYPTING SECTION:
#1 change hex pairs to decimal
#2 xor with the key
#3 convert decimal to binary
#4 flip binary
#5 convert binary to decimal
#6 convert decimal to hex
#7 convert hex to ascii




def string_to_hex(word):
	hex_equivalent = binascii.hexlify(word.encode()) 
	hex_equivalent = str(hex_equivalent, 'ascii')
	return hex_equivalent

def hexstr_to_binarystr(hexstr):
	bin_equivalent = ""
	for i in range(0, len(hexstr), 2):
		bin_equivalent += "{0:08b} ".format(int(hexstr[i:i+2], 16)) 
	return bin_equivalent

def flip_binarystr(binarystr):
	flipped_equivalent = ""
	for bit in binarystr:
		if bit == '1':
			flipped_equivalent += '0'
		elif bit == '0':
			flipped_equivalent += '1'
		elif bit == ' ':
			flipped_equivalent += ' '
	return flipped_equivalent

def binarystr_to_decimal(binarystr):
	decimal_equivalent = [] #4
	for binary_char in binarystr.split(' '): 
		if len(binary_char) > 0:
			decimal_equivalent.append(int(binary_char, 2))
	return decimal_equivalent

def xor_decimal_list(decimal_list, key):
	xored_decimal = [] #5
	for i in range(0, len(decimal_list)): 
		xored_decimal.append(decimal_list[i]^ord(key[i%len(key)]))
	return xored_decimal

def decimal_list_to_hex_list(decimal_list):
	hex_list = [] #6
	for i in decimal_list:
		hex_list.append(str(hex(i))[2:])
	return hex_list

def encrypt(word, key):
	print("encrypting...")
	hex_equivalent = string_to_hex(word) #1
	print("plaintext as hex:\t\t",hex_equivalent)

	bin_equivalent = hexstr_to_binarystr(hex_equivalent) #2
	print("binary equivalent:\t\t",bin_equivalent) 

	flipped_equivalent = flip_binarystr(bin_equivalent) #3
	print("flipped equivalent:\t\t",flipped_equivalent)

	decimal_equivalent = binarystr_to_decimal(flipped_equivalent) #4
	print("decimal equivalent:\t\t",*decimal_equivalent)

	xored_decimal = xor_decimal_list(decimal_equivalent, key) #5
	print("encrypted string as decimal:\t",*xored_decimal)

	encrypted_vals = decimal_list_to_hex_list(xored_decimal) #6
	print("encrypted string as hex:\t",*encrypted_vals)

	return ''.join(encrypted_vals)


def decrypt(ciphertext, key):
	print("decrypting...")
	decimal_eq_of_ct = [int(ciphertext[i:i+2], 16) for i in range(0, len(ciphertext),2)] #1
	print(*decimal_eq_of_ct)

	xored_decimal = xor_decimal_list(decimal_eq_of_ct, key) #2
	print(*xored_decimal)

	binary_list = [ str(bin(i))[2:] for i in xored_decimal] #3
	binary_str = ' '.join(binary_list)
	print(binary_str)

	flipped_binary = flip_binarystr(binary_str) #4
	print(flipped_binary)

	decimal_list = binarystr_to_decimal(flipped_binary) #5
	print(*decimal_list)

	hex_list = [str(hex(i)) for i in decimal_list] #6
	print(*hex_list)

	plaintext = [binascii.unhexlify(i[2:]).decode() for i in hex_list]
	print(*plaintext)

	return ''.join(plaintext)






def main():
	word = input('enter the plaintext string: ')
	key = input('enter the key: ')
	ciphertext = encrypt(word, key)
	plaintext=decrypt(ciphertext, key)
	print(plaintext)
	

if __name__ == "__main__":
	main()


