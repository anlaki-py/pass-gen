document.addEventListener('DOMContentLoaded', (event) => {
    const audio = document.getElementById('backgroundMusic');
    const toggle = document.querySelector('.toggle'); // Using the class to select the toggle
    const volumeControl = document.getElementById('volumeControl');

    // Event listener for the toggle switch
    toggle.addEventListener('change', () => {
        if (toggle.checked) {
            audio.play().then(() => {
                console.log("Audio playing");
            }).catch(e => console.error("Audio play failed:", e));
        } else {
            audio.pause();
            console.log("Audio paused");
        }
    });

    // Adjust the audio volume based on the slider's value
    volumeControl.addEventListener('input', () => {
        audio.volume = volumeControl.value;
    });

    // Initialize volume
    audio.volume = volumeControl.value;
});
