using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Razbijanje_gesel
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

        }


        private static char[] words =
            {
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'r', 'q', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','Q','S','T','U','V','W','X','Y','Z',
                '0','1','2','3','4','5','6','7','8','9'
            };

        private bool najden;
        private string rezultat;
        private int chartoTest = 0;
        private string source;
        public string[] datoteka;
        public int stevec = 0;

       


        private void slovar_TabStopChanged(object sender, EventArgs e)
        {
            if (slovar.TabStop == true)
                st_znakov.Enabled = false;
            else
                st_znakov.Enabled = true;
        }

     
        private void razbij_Click(object sender, EventArgs e)
        {

            Dictionary<string, string> dict = new Dictionary<string, string>();

            najden = false;
            stevec = 0;

            source = vrednost.Text;

            Stopwatch time = new Stopwatch();
            time.Start();


            if(md5.TabStop == true && groba_sila.TabStop == true)
            {

                int dol = Convert.ToInt32(st_znakov.Text);

                TimeSpan ts = time.Elapsed;


                chartoTest = words.Length;
                
                var dolzina_gesla = 0;
                while (!najden)
                {

                    dolzina_gesla++;
                    BruteForce(dolzina_gesla);

                    if (dolzina_gesla == dol)
                        break;
                }

                if (najden == true)
                {
                    time.Stop();
                    cas.Text = (time.Elapsed.TotalMinutes).ToString("N2") + " min";
                    geslo.Text = rezultat;
                    geslo.BackColor = Color.LightGreen;
                    status.Text = "Končano";
                }
                else
                {
                    time.Stop();
                    cas.Text = (time.Elapsed.TotalMinutes).ToString("N2") + " min";
                    geslo.BackColor = Color.Red;
                    geslo.Text = "Geslo ni najdeno!";
                }
            }

            if (sha1.TabStop == true && groba_sila.TabStop == true)
            {

                int dol = Convert.ToInt32(st_znakov.Text);

                TimeSpan ts = time.Elapsed;

                chartoTest = words.Length;

                var dolzina_gesla = 0;
                while (!najden)
                {

                    dolzina_gesla++;
                    BruteForce(dolzina_gesla);

                    if (dolzina_gesla == dol)
                        break;
                }

                if (najden == true)
                {
                    time.Stop();
                    cas.Text = (time.Elapsed.TotalMinutes).ToString("N2") + " min";
                    geslo.Text = rezultat;
                    geslo.BackColor = Color.LightGreen;
                    status.Text = "Končano";
                }
                else
                {
                    time.Stop();
                    cas.Text = (time.Elapsed.TotalMinutes).ToString("N2") + " min";
                    geslo.BackColor = Color.Red;
                    geslo.Text = "Geslo ni najdeno!";
                }

            }

            if (md5.TabStop == true && slovar.TabStop == true)
            {

                string[] lines = System.IO.File.ReadAllLines(@"dictionary_english.dic");
                TimeSpan ts = time.Elapsed;

                foreach (string s in lines)
                {
                    dict.Add(GetMD5HashData(s), s);
                }
                string vrne = null;
                if (dict.TryGetValue(vrednost.Text, out vrne))
                {
                    time.Stop();
                    cas.Text = (time.Elapsed.TotalMinutes).ToString("N2") + " min";
                    geslo.Text = vrne;
                    geslo.BackColor = Color.LightGreen;
                    status.Text = "Končano";
                    return;
                }
                else
                {
                    time.Stop();
                    cas.Text = (time.Elapsed.TotalMinutes).ToString("N2") + " min";
                    geslo.BackColor = Color.Red;
                    geslo.Text = "Geslo ni najdeno!";
                }

            }

            if (sha1.TabStop == true && slovar.TabStop == true)
            {

                string[] lines = System.IO.File.ReadAllLines(@"dictionary_english.dic");
                TimeSpan ts = time.Elapsed;

                foreach (string s in lines)
                {
                    dict.Add(GetSHA1HashData(s), s);
                }
                string vrne = null;
                if (dict.TryGetValue(vrednost.Text, out vrne))
                {
                    time.Stop();
                    cas.Text = (time.Elapsed.TotalMinutes).ToString("N2") + " min";
                    geslo.Text = vrne;
                    geslo.BackColor = Color.LightGreen;
                    status.Text = "Končano";
                    return;
                }
                else
                {
                    time.Stop();
                    cas.Text = (time.Elapsed.TotalMinutes).ToString("N2") + " min";
                    geslo.BackColor = Color.Red;
                    geslo.Text = "Geslo ni najdeno!";
                }
                    
            }
        }

        
        private void BruteForce(int dolzina)
        {
            //naredi char array dolzine gesla
            var keyChars = createCharArray(dolzina, words[0]);
            // index zadnjega znaka
            var indexOfLastChar = dolzina - 1;
            createNewKey(0, keyChars, dolzina, indexOfLastChar); 
         
        }

        private char[] createCharArray(int length, char defaultChar)
        {
            return (from c in new char[length] select defaultChar).ToArray();
        }

        private void createNewKey(int currentCharPosition, char[] keyChars, int keyLength, int indexOfLastChar)
        {
            var nextCharPosition = currentCharPosition + 1;
            // gremo skozi celotne dolzine words(črk)
            for (int i = 0; i < chartoTest; i++)
            {
                // zamenjamo črko na trenutnem mestu
                keyChars[currentCharPosition] = words[i];
                // funkcijo kličemo rekurzivno dokler ne zamenjamo vseh črk
                if (currentCharPosition < indexOfLastChar)
                {
                    createNewKey(nextCharPosition, keyChars, keyLength, indexOfLastChar);
                }
                else
                {
                    
                    // md5 
                    if (md5.TabStop == true)
                    {
                        // primerja hash vrednosti
                        if (ValidateMD5HashData((new String(keyChars)), source) == true)
                        {
                            //če sta enaki potem prekine in vrne geslo v rezultat
                            if (!najden)
                            {
                                najden = true;
                                rezultat = new String(keyChars);
                            }
                            return;
                        }
                    }
                    // sha1
                    else if (sha1.TabStop == true)
                    {
                        // primerja hash vrednosti
                        if (ValidateSHA1HashData((new String(keyChars)), source) == true)
                        {
                            //če sta enaki potem prekine in vrne geslo v rezultat
                            if (!najden)
                            {
                                najden = true;
                                rezultat = new String(keyChars);
                            }
                            return;
                        }
                    }
                    
                }
            }
        }

        #region MD5 and SHA1

        private string GetMD5HashData(string data)
        {
            //create new instance of md5
            MD5 md5 = MD5.Create();

            //convert the input text to array of bytes
            byte[] hashData = md5.ComputeHash(Encoding.Default.GetBytes(data));

            //create new instance of StringBuilder to save hashed data
            StringBuilder returnValue = new StringBuilder();

            //loop for each byte and add it to StringBuilder
            for (int i = 0; i < hashData.Length; i++)
            {
                returnValue.Append(hashData[i].ToString("x2"));
            }

            // return hexadecimal string
            return returnValue.ToString();

        }

        // Verify a hash against a string. 
        private bool ValidateMD5HashData(string inputData, string storedHashData)
        {
            //hash input text and save it string variable
            string getHashInputData = GetMD5HashData(inputData);

            if (string.Compare(getHashInputData, storedHashData) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private string GetSHA1HashData(string data)
        {
            //create new instance of md5
            SHA1 sha1 = SHA1.Create();

            //convert the input text to array of bytes
            byte[] hashData = sha1.ComputeHash(Encoding.Default.GetBytes(data));

            //create new instance of StringBuilder to save hashed data
            StringBuilder returnValue = new StringBuilder();

            //loop for each byte and add it to StringBuilder
            for (int i = 0; i < hashData.Length; i++)
            {
                returnValue.Append(hashData[i].ToString("x2"));
            }

            // return hexadecimal string
            return returnValue.ToString();
        }

        private bool ValidateSHA1HashData(string inputData, string storedHashData)
        {
            //hash input text and save it string variable
            string getHashInputData = GetSHA1HashData(inputData);

            if (string.Compare(getHashInputData, storedHashData) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    #endregion

        

    }
}