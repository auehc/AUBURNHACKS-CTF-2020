# Prompt
We found this very large image on a confiscated flashdrive, see what you can recover.
https://drive.google.com/file/d/1hQZ5vXtDvEHXSknqEjZFyOu6xJRIRcZE/view?usp=sharing

# Solution
`binwalk` the image to get a NTFS `dd` file.
Use tool of choice to extract deleted zip file `flag.zip`.
Use _John the Ripper_ or `fcrackzip` to crack the zip file password.
Unzip the file using found password and retrieve flag
