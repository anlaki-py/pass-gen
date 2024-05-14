 document.addEventListener('DOMContentLoaded', function () {
    const checkbox = document.querySelector('.checkbox');
    // Check for saved 'darkMode' in localStorage
    if (localStorage.getItem('darkMode') === 'true') {
      document.body.classList.add('dark-mode');
      checkbox.checked = true;
    } else {
      document.body.classList.add('light-mode');
    }

    checkbox.addEventListener('change', function() {
      document.body.classList.toggle('dark-mode', this.checked);
      document.body.classList.toggle('light-mode', !this.checked);
      
      // Save the state in localStorage
      localStorage.setItem('darkMode', this.checked);
    });
  });