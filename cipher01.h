/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Alex Braddock"; }
   virtual std::string getCipherName()  { return "Autokey Cipher"; }
   virtual std::string getEncryptAuth() { return "Alex Braddock"; }
   virtual std::string getDecryptAuth() { return "Alex Braddock"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citations;
      citations += "\"Autokey Cipher\", Practical Cryptography. Retrieved from:\nhttp://practicalcryptography.com/ciphers/classical-era/autokey/\n";
      citations += "\n\"Autokey Cipher\", Crypto Corner. Retrieved from:\nhttps://crypto.interactive-maths.com/autokey-cipher.html\n";
      citations += "\n\"Autokey Cipher | Symmetric Ciphers\", GeeksforGeeks, May 10, 2020. Retrieved from:\nhttps://www.geeksforgeeks.org/autokey-cipher-symmetric-ciphers/";
      return citations;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "insert the encryption pseudocode\n";
      str += "\ntable = createTablaRecta() // https://en.wikipedia.org/wiki/Tabula_recta\n";
      str += "// Only add letters from plainText to OtherKey until the length of otherKey is the same as the length of plainText\n";
      str += "otherKey = password + plainText.substr(lengthOfPlainText - lengthOfPassword)\n";
      str += "for letter in plainText\n";
      str += "\tcipherText += table[plaintext letter][otherKey letter]\n";
      str += "return cipherText\n";

      // The decrypt pseudocode
      str += "\ninsert the decryption pseudocode\n";
      str += "\ntable = createTablaRecta()\n";
      str += "for letter in cipherText\n";
      str += "\tfor column in table\n";
      str += "\t\tif table[letter.AsciiValue][column] == letter\n";
      str += "\t\t\tplainText += column.int_to_char\n";
      str += "return plainText";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Turns plaintext into cipher text using a password
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      std::string cipherText;
      // otherKey is the password with the plain text appended until the length of otherKey
      // matches the length of the plaintext
      std::string otherKey = password + plainText.substr(0, plainText.length() - password.length());

      // Create table of ascii characters
      char table[95][95];
      for(int i = 0; i < 95; i++)
      {
         for(int j = 0; j < 95; j++)
         {
            if(32 + j + i > 126)
            {
               table[i][j] = j + i -63;
            }
            else{
               table[i][j] = 32 + j + i;
            }
            
         }
      }
      
      for(int i = 0; i < plainText.length(); i++)
      {
         // cipher character is the column and row of the table 
         // that matches the char value for plainText[i] and otherKey[i]
         cipherText.push_back(table[(int)plainText[i] -32][(int)otherKey[i] - 32]);
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * Decrypts cipher text using a password
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      std::string otherKey = password;

      // Create table of ascii characters
      char table[95][95];
      for(int i = 0; i < 95; i++)
      {
         for(int j = 0; j < 95; j++)
         {
            if(32 + j + i > 126)
            {
               table[i][j] = j + i -63;
            }
            else{
               table[i][j] = 32 + j + i;
            }
            
         }
      }

      // Iterate through every letter of the cipher text
      for(int i = 0; i < cipherText.length(); i++)
      {
         char letterToAdd;
         // Iterate through every row in the ascii table
         for(int j = 0; j < 95; j++)
         {
            // If the character in the ascii table = the letter from the cipher text
            // then the letter we need to add is the column header in the ascii table
            if(table[(int)otherKey[i] - 32][j] == cipherText[i])
            {
               letterToAdd = j + 32;
               j = 95; // Stop iterating through the table
            }
         }
         otherKey.push_back(letterToAdd);

      }
      // The plain text is the other key with the password shaved off the front
      std::string plainText = otherKey.substr(password.length());
      return plainText;
   }
};

#endif // CIPHER01_H