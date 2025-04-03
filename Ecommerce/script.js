// Toggle between dark and light themes
function toggleTheme() {
    document.body.classList.toggle('dark');
}

// Add animations for page load
window.onload = () => {
    document.body.style.opacity = 1;
    document.body.style.transition = 'opacity 0.5s ease-in';
    document.body.style.opacity = 1;
};
