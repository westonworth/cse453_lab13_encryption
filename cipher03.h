/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Weston Gavin"; }
   virtual std::string getCipherName()  { return "Columnar Transposition"; }
   virtual std::string getEncryptAuth() { return "Weston Gavin"; }
   virtual std::string getDecryptAuth() { return "Weston Gavin"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Kahn, David. The Codebreakers: The Story of Secret Writing. Rev Sub. Scribner, 1996.");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      
      str =  "Columnar Transposition\n";
      str += "GET password LENGTH\n";
      str += "CREATE multi-dimensional array\n";
      str += "SET Row Lengths = password LENGTH\n";
      str += "SET counter = 0\n";
      str += "COUNT rows & leftover elements on last row\m;
      str += "WRITE until rows and columns exceeded\n";
      // The decrypt pseudocode
      str += "Decryption Pseudocode\n";
      str += "GET password LENGTH\n";
      str += "SET Row Lengths = password LENGTH\n";
      str += "SET counter = 0\n";
      str += "READ letters at row length offsets until rows and columns exceeded\n;

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      int numCols = password.length();
      int colModulusCountdown = plainText.length() % numCols;
      int rowCounter = (plainText.length() / password.length()) + 1;

      char array[100][100];
      int counter = 0;
      for (int j = 0; j < rowCounter; j++)
      {
         for (int i = 0; i < password.length(); i++)
            {
               if ((j != rowCounter) || (i < colModulusCountdown))
                  {
                     array[j][i] = plainText[counter];
                     counter++;
                  }
            }
    
      }
      string cipherText;
      for (int k = 0; k < password.length(); k++)
         {
            for (int l = 0; j < rowCounter; l++)
               {
                  if ((l != rowCounter) || (k < colModulusCountdown))
               {
                ciphertext += array[l][k];
         }
    }   
}
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      int numCols = password.length();
      int colModulusCountdown = cipherText.length() % numCols;
      int rowCounter = (cipherText.length() / password.length()) + 1;
      
      for (int colLetter = 0; colLetter < password.length(); colLetter++)
      {
         int newCount = 0;
         while (newCount < cipherText.length())
         {
            std::cout << cipherText[newCount];
            newCount += password.length();
         }
       }
      return plainText;
   }
};

#endif // CIPHER03_H
