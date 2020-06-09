namespace Razbijanje_gesel
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.sha1 = new System.Windows.Forms.RadioButton();
            this.md5 = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.slovar = new System.Windows.Forms.RadioButton();
            this.groba_sila = new System.Windows.Forms.RadioButton();
            this.vrednost = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.st_znakov = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.geslo = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.cas = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.nit = new System.Windows.Forms.TextBox();
            this.status = new System.Windows.Forms.TextBox();
            this.razbij = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.sha1);
            this.groupBox1.Controls.Add(this.md5);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 100);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = " Zgoščevalna funkcija";
            // 
            // sha1
            // 
            this.sha1.AutoSize = true;
            this.sha1.Location = new System.Drawing.Point(6, 51);
            this.sha1.Name = "sha1";
            this.sha1.Size = new System.Drawing.Size(53, 17);
            this.sha1.TabIndex = 1;
            this.sha1.TabStop = true;
            this.sha1.Text = "SHA1";
            this.sha1.UseVisualStyleBackColor = true;
            // 
            // md5
            // 
            this.md5.AutoSize = true;
            this.md5.Location = new System.Drawing.Point(6, 28);
            this.md5.Name = "md5";
            this.md5.Size = new System.Drawing.Size(48, 17);
            this.md5.TabIndex = 0;
            this.md5.TabStop = true;
            this.md5.Text = "MD5";
            this.md5.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.slovar);
            this.groupBox2.Controls.Add(this.groba_sila);
            this.groupBox2.Location = new System.Drawing.Point(12, 142);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(200, 100);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Metoda";
            // 
            // slovar
            // 
            this.slovar.AutoSize = true;
            this.slovar.Location = new System.Drawing.Point(11, 57);
            this.slovar.Name = "slovar";
            this.slovar.Size = new System.Drawing.Size(79, 17);
            this.slovar.TabIndex = 3;
            this.slovar.TabStop = true;
            this.slovar.Text = "S slovarjem";
            this.slovar.UseVisualStyleBackColor = true;
            this.slovar.TabStopChanged += new System.EventHandler(this.slovar_TabStopChanged);
            // 
            // groba_sila
            // 
            this.groba_sila.AutoSize = true;
            this.groba_sila.Location = new System.Drawing.Point(11, 34);
            this.groba_sila.Name = "groba_sila";
            this.groba_sila.Size = new System.Drawing.Size(72, 17);
            this.groba_sila.TabIndex = 2;
            this.groba_sila.TabStop = true;
            this.groba_sila.Text = "Grobe sile";
            this.groba_sila.UseVisualStyleBackColor = true;
            // 
            // vrednost
            // 
            this.vrednost.Location = new System.Drawing.Point(236, 40);
            this.vrednost.Multiline = true;
            this.vrednost.Name = "vrednost";
            this.vrednost.Size = new System.Drawing.Size(532, 72);
            this.vrednost.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(233, 153);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(107, 17);
            this.label1.TabIndex = 3;
            this.label1.Text = "Število znakov: ";
            // 
            // st_znakov
            // 
            this.st_znakov.Location = new System.Drawing.Point(346, 153);
            this.st_znakov.Name = "st_znakov";
            this.st_znakov.Size = new System.Drawing.Size(100, 20);
            this.st_znakov.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label2.Location = new System.Drawing.Point(480, 135);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(98, 17);
            this.label2.TabIndex = 5;
            this.label2.Text = "Razbito geslo:";
            // 
            // geslo
            // 
            this.geslo.Location = new System.Drawing.Point(584, 134);
            this.geslo.Name = "geslo";
            this.geslo.Size = new System.Drawing.Size(184, 20);
            this.geslo.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label3.Location = new System.Drawing.Point(494, 177);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(84, 17);
            this.label3.TabIndex = 7;
            this.label3.Text = "Čas iskanja:";
            // 
            // cas
            // 
            this.cas.Location = new System.Drawing.Point(584, 176);
            this.cas.Name = "cas";
            this.cas.Size = new System.Drawing.Size(184, 20);
            this.cas.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label4.Location = new System.Drawing.Point(545, 212);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(33, 17);
            this.label4.TabIndex = 9;
            this.label4.Text = "Nit: ";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label5.Location = new System.Drawing.Point(522, 245);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(56, 17);
            this.label5.TabIndex = 10;
            this.label5.Text = "Status: ";
            // 
            // nit
            // 
            this.nit.Location = new System.Drawing.Point(584, 211);
            this.nit.Name = "nit";
            this.nit.Size = new System.Drawing.Size(184, 20);
            this.nit.TabIndex = 11;
            // 
            // status
            // 
            this.status.Location = new System.Drawing.Point(584, 244);
            this.status.Name = "status";
            this.status.Size = new System.Drawing.Size(184, 20);
            this.status.TabIndex = 12;
            // 
            // razbij
            // 
            this.razbij.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.razbij.Location = new System.Drawing.Point(236, 211);
            this.razbij.Name = "razbij";
            this.razbij.Size = new System.Drawing.Size(210, 63);
            this.razbij.TabIndex = 13;
            this.razbij.Text = "RAZBIJ GESLO";
            this.razbij.UseVisualStyleBackColor = true;
            this.razbij.Click += new System.EventHandler(this.razbij_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label6.Location = new System.Drawing.Point(236, 21);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(152, 17);
            this.label6.TabIndex = 14;
            this.label6.Text = "Zgoščevalna vrednost:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(795, 299);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.razbij);
            this.Controls.Add(this.status);
            this.Controls.Add(this.nit);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.cas);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.geslo);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.st_znakov);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.vrednost);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton sha1;
        private System.Windows.Forms.RadioButton md5;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton slovar;
        private System.Windows.Forms.RadioButton groba_sila;
        private System.Windows.Forms.TextBox vrednost;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox st_znakov;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox geslo;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox cas;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox nit;
        private System.Windows.Forms.TextBox status;
        private System.Windows.Forms.Button razbij;
        private System.Windows.Forms.Label label6;
    }
}

