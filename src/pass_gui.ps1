Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

# Create the main form
$form = New-Object System.Windows.Forms.Form
$form.Text = "PASS-GEN GUI v1.0.3"
$form.Size = New-Object System.Drawing.Size(400,450)
$form.StartPosition = "CenterScreen"
$form.FormBorderStyle = "FixedDialog"
$form.MaximizeBox = $false

# Create a custom font
$customFont = New-Object System.Drawing.Font("Segoe UI", 10)

# Function to create labels
function Create-Label ($text, $x, $y, $width, $height) {
    $label = New-Object System.Windows.Forms.Label
    $label.Location = New-Object System.Drawing.Point($x, $y)
    $label.Size = New-Object System.Drawing.Size($width, $height)
    $label.Text = $text
    $label.Font = $customFont
    $form.Controls.Add($label)
}

# Function to create checkboxes
function Create-Checkbox ($text, $x, $y, $width, $height) {
    $checkbox = New-Object System.Windows.Forms.CheckBox
    $checkbox.Location = New-Object System.Drawing.Point($x, $y)
    $checkbox.Size = New-Object System.Drawing.Size($width, $height)
    $checkbox.Text = $text
    $checkbox.Font = $customFont
    $form.Controls.Add($checkbox)
    return $checkbox
}

# Create labels
Create-Label "Password Length:" 20 20 150 20
Create-Label "Options:" 20 60 100 20

# Create length input
$lengthInput = New-Object System.Windows.Forms.NumericUpDown
$lengthInput.Location = New-Object System.Drawing.Point(180, 20)
$lengthInput.Size = New-Object System.Drawing.Size(60, 20)
$lengthInput.Minimum = 1
$lengthInput.Maximum = 100
$lengthInput.Value = 8
$lengthInput.Font = $customFont
$form.Controls.Add($lengthInput)

# Create checkboxes
$uppercaseCheck = Create-Checkbox "Include uppercase letters (-u)" 20 90 300 20
$numbersCheck = Create-Checkbox "Include numbers (-n)" 20 120 300 20
$symbolsCheck = Create-Checkbox "Include symbols (-s)" 20 150 300 20
$easyCheck = Create-Checkbox "Generate easy-to-remember password (-e)" 20 180 300 20

# Create generate button
$generateButton = New-Object System.Windows.Forms.Button
$generateButton.Location = New-Object System.Drawing.Point(20, 220)
$generateButton.Size = New-Object System.Drawing.Size(340, 30)
$generateButton.Text = "Generate Password"
$generateButton.Font = $customFont
$form.Controls.Add($generateButton)

# Create result textbox
$resultTextBox = New-Object System.Windows.Forms.TextBox
$resultTextBox.Location = New-Object System.Drawing.Point(20, 270)
$resultTextBox.Size = New-Object System.Drawing.Size(340, 30)
$resultTextBox.Font = New-Object System.Drawing.Font("Consolas", 12)
$resultTextBox.ReadOnly = $true
$form.Controls.Add($resultTextBox)

# Create copy button
$copyButton = New-Object System.Windows.Forms.Button
$copyButton.Location = New-Object System.Drawing.Point(20, 310)
$copyButton.Size = New-Object System.Drawing.Size(340, 30)
$copyButton.Text = "Copy to Clipboard"
$copyButton.Font = $customFont
$copyButton.Enabled = $false
$form.Controls.Add($copyButton)

# Create version label
$versionLabel = New-Object System.Windows.Forms.Label
$versionLabel.Location = New-Object System.Drawing.Point(20, 380)
$versionLabel.Size = New-Object System.Drawing.Size(340, 20)
$versionLabel.Text = "PASS-GEN v1.0.3"
$versionLabel.Font = New-Object System.Drawing.Font("Segoe UI", 8)
$versionLabel.ForeColor = [System.Drawing.Color]::Gray
$versionLabel.TextAlign = [System.Drawing.ContentAlignment]::MiddleCenter
$form.Controls.Add($versionLabel)

# Generate password function
$generateButton.Add_Click({
    $length = $lengthInput.Value
    $options = @($length)
    
    if ($uppercaseCheck.Checked) { $options += "-u" }
    if ($numbersCheck.Checked) { $options += "-n" }
    if ($symbolsCheck.Checked) { $options += "-s" }
    if ($easyCheck.Checked) { $options += "-e" }
    
    $cmd = "..\bin\pass.exe $options"
    
    # Execute the command
    $result = & cmd.exe /c $cmd
    $resultTextBox.Text = $result.Trim()
    $copyButton.Enabled = $true
})

# Copy to clipboard function
$copyButton.Add_Click({
    if ($resultTextBox.Text -ne "") {
        [System.Windows.Forms.Clipboard]::SetText($resultTextBox.Text)
        [System.Windows.Forms.MessageBox]::Show("Password copied to clipboard!", "Success", [System.Windows.Forms.MessageBoxButtons]::OK, [System.Windows.Forms.MessageBoxIcon]::Information)
    }
})

# Show the form
$form.ShowDialog()
