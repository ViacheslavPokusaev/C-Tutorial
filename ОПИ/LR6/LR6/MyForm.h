#pragma once
#include <iomanip>
#include <string>

namespace LR6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input rows:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(226, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Input columns:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(117, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(55, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(359, 15);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(55, 20);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(448, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(161, 33);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Fill";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(17, 47);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(592, 222);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellEndEdit);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(17, 275);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(592, 70);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Change table";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(625, 357);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"LR6";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if ((textBox1->Text != "") && (textBox2->Text != ""))
		{
			if (Convert::ToInt64(textBox1->Text) >= 1 && Convert::ToInt64(textBox2->Text) >= 1)
			{
				dataGridView1->ColumnCount = Convert::ToInt64(textBox1->Text);
				dataGridView1->RowCount = Convert::ToInt64(textBox2->Text);
				for (int i = 0; i < dataGridView1->RowCount; i++)
				{
					for (int j = 0; j < dataGridView1->ColumnCount; j++)
					{
						dataGridView1->Rows[i]->Cells[j]->Value = Convert::ToString((rand() %
							(dataGridView1->RowCount * dataGridView1->ColumnCount)) -
							((dataGridView1->RowCount + dataGridView1->ColumnCount)));
					}
				}
			}
			else
			{
				MessageBox::Show("You shouldn't input negative numbers and zero!!!");
				textBox1->Text = "";
				textBox2->Text = "";
			}
		}
		else
		{
			MessageBox::Show("Fill in all textBoxes!");
		}
	}
	private: System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		try
		{
			int value = Convert::ToInt64(dataGridView1->CurrentCell->Value);
		}
		catch (SystemException^ ex)
		{
			MessageBox::Show("Please input only numbers!");
			dataGridView1->CurrentCell->Value = "";
		}
	}

		   void Main_algorithm()
		   {
			   bool end = true;
			   int i = 0;

			   while (end)
			   {
				   Change_array(i);
				   if (++i == dataGridView1->ColumnCount) end = false;
			   }
		   }

		   void Change_array(int current_column)
		   {
			   int count = 0, Max = 0;
			   String ^str1, ^str2;
			   str1 = str2 = "";
			   float average = 0;

			   for (int i = 0, j = dataGridView1->RowCount - 1; i < dataGridView1->RowCount; i++, j--)
			   {
				   str1 += Convert::ToString(dataGridView1->Rows[i]->Cells[current_column]->Value) + '0';
				   str2 += Convert::ToString(dataGridView1->Rows[j]->Cells[current_column]->Value) + '0';
				   if (Convert::ToInt64(dataGridView1->Rows[i]->Cells[current_column]->Value != 0)) 
				   { average += Convert::ToDouble
				   (dataGridView1->Rows[i]->Cells[current_column]->Value); 
				   count++; }
			   }

			   count != 0 && str1 == str2 ?
				   Change_polidrom(current_column, average /= count) :
				   Change_other_array(current_column, str2);
		   }

		   void Change_polidrom(int current_column, float avr)
		   {
			   float Max = 0;

			   for (int i = 0; i < dataGridView1->RowCount; i++)
				   if (Max <= Convert::ToDouble(dataGridView1->Rows[i]->Cells[current_column]->Value))
					   Max = Convert::ToDouble(dataGridView1->Rows[i]->Cells[current_column]->Value);

			   for (int i = 0; i < dataGridView1->RowCount; i++)
				   if (Convert::ToInt64(dataGridView1->Rows[i]->Cells[current_column]->Value) == Max)
					   dataGridView1->Rows[i]->Cells[current_column]->Value = Convert::ToString(avr);
		   }

		   void Change_other_array(int current_column, String ^str)
		   {
			   for (int i = 0; i < dataGridView1->RowCount; i++)
				   dataGridView1->Rows[i]->Cells[current_column]->Value = Convert::ToString(str[i] - '0');
		   }

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Main_algorithm();
	}
};
}
