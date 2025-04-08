<script>
  // Dark/Light theme toggle
  const toggle = document.getElementById('theme-toggle');
  if (toggle) { // Ensure the toggle element exists
    toggle.addEventListener('click', () => {
      document.body.classList.toggle('dark');
    })
  }

  // Scroll-based fade-in and slide-in
  const faders = document.querySelectorAll('.fade-in, .slide-in');
  const observer = new IntersectionObserver(entries = {
    entries.forEach(entry => {
      if (entry.isIntersecting) {
        entry.target.classList.add('visible');
      } else {
        // Optional: Remove 'visible' class when element is out of view
        // entry.target.classList.remove('visible');
      }
    })
  });

  faders.forEach(fader = observer.observe(fader));
</script>