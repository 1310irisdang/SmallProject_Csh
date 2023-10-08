using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MatchingGame
{
    public partial class Form1 : Form
    {
        Image[] pictures = {
            Properties.Resources.barbara,
            Properties.Resources.kokomi,
            Properties.Resources.miko,
            Properties.Resources.ningguang,
            Properties.Resources.raiden,
            Properties.Resources.venti,
            Properties.Resources.xiao,
            Properties.Resources.yoimiya
        };

        int[] index = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };

        PictureBox firstBox;
        int firstIndex, found; 

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            mixPicture();
        }

        private void mixPicture()
        {
            Random rnd = new Random();
            for (int i = 0; i < 16; i++)
            {
                //Change position random
                int num = rnd.Next(16);
                int temp = index[i];
                index[i] = index[num];
                index[num] = temp;
            }
        }

        private void card1_Click(object sender, EventArgs e)
        {
            PictureBox box = (PictureBox) sender;
            int boxNo = int.Parse(box.Name.Substring(4));
            int indexNo = index[boxNo - 1];
            box.Image = pictures[indexNo];
            box.Refresh();

            if (firstBox == null)
            {
                firstBox = box;
                firstIndex = indexNo;
            }
            else
            {
                System.Threading.Thread.Sleep(1000);

                firstBox.Image = null;
                box.Image = null;

                if (firstIndex == indexNo) 
                {
                    found++;
                    firstBox.Visible = false;
                    box.Visible = false;

                    if (found == 8)
                    {
                        MessageBox.Show("Congratulations!");
                        found = 0;
                        foreach (Control ctrl in Controls)
                        {
                            ctrl.Visible = true;
                        }
                        mixPicture();
                    }
                }
                firstBox = null;

            }
        
        }
    }
}
