# MayuGram

**MayuGram** (Clean AyuGram), [AyuGram Desktop](https://github.com/AyuGram/AyuGramDesktop)'un geliştirici sunucularıyla hiçbir otomatik bağlantı kurmayan bir fork'udur. Uygulama yalnızca Telegram sunucularıyla iletişim kurar.

Orijinal AyuGram'dan kaldırılanlar:

| Kaldırılan | Ne yapıyordu |
| --- | --- |
| Uzaktan yapılandırma (RC Manager) | Saatte bir `update.ayugram.one` ve `api.exteragram.app` adreslerinden liste indiriyordu |
| Çökme raporu gönderimi | Rapor ve bellek dökümünü `sentry.radolyn.com` adresine yüklüyordu; ayarlardaki düğmesi de kaldırıldı |
| Otomatik güncelleyici | `update.ayugram.one` ve Telegram kanalından güncelleme dosyası indirip çalıştırıyordu |
| AyuGram dil paketi indirmesi | `cdn.jsdelivr.net/gh/AyuGram/Languages` adresinden çeviri indiriyordu; önbellekteki dosyalar kullanılmaya devam eder |
| Kayıt tarihi sorgusu | Bakılan kullanıcının ID'sini `@ayugrambot` / `@exteraAuthBot` botlarına gönderiyordu; profildeki düğme kullanıcılar için gizlendi |
| Müzik kapağı araması | Profildeki şarkıların adını `itunes.apple.com` adresine gönderiyordu |
| Google / Yandex çevirmeni | Çevrilecek mesaj metnini Google ve Yandex sunucularına gönderiyordu; çeviri artık yalnızca Telegram'ın kendi çevirmeniyle yapılır |
| Filtreleri linkle paylaşma / içe aktarma | Filtre listesini `dpaste.com`'a yüklüyor, verilen herhangi bir linkten indiriyordu; artık yalnızca panoya kopyalama ve panodan içe aktarma var |

Güncellemeler otomatik gelmez; yeni sürüm için bu depoyu kendiniz güncelleyip derleyin.

Telegram Desktop'un kendisinden gelen ve Telegram'ın normal çalışmasının parçası olan bağlantılar bilerek bırakıldı: Telegram engelliyse bağlantı adresini bulmak için kullanılan DNS-over-HTTPS / yedek yapılandırma istekleri, ödeme sağlayıcıları (Stripe, SmartGlocal; yalnızca ödeme yaparken), konum gönderirken adres arama (Mapbox), mesajdaki linkler ve bağlantı önizlemeleri.

*English:* MayuGram (Clean AyuGram) is a fork of AyuGram Desktop with every non-Telegram endpoint added by AyuGram removed (remote config, crash report upload, auto-updater, language pack download, registration-date bots, iTunes cover lookup, Google/Yandex translators, dpaste filter sharing). The app talks only to Telegram, apart from the network features that come from upstream Telegram Desktop itself.

---

![AyuGram Logo](.github/AyuGram.png) ![AyuChan](.github/AyuChan.png)

[ English  |   [Русский](README-RU.md) ]

## Features

- Full ghost mode (flexible)
- Messages history
- Anti-recall
- Font customization
- Streamer mode
- Local Telegram Premium
- Translator
- Media preview & quick reaction on force click (macOS)
- Enhanced appearance

And many more. Check out our [Documentation](https://docs.ayugram.one/desktop/).

<h3>
  <details>
    <summary>Preview</summary>
    <table>
      <tr>
        <td><img src='.github/demos/demo1.png' width='268' alt='Preferences'></td>
        <td><img src='.github/demos/demo2.png' width='268' alt='AyuGram Options'></td>
        <td><img src='.github/demos/demo3.png' width='268' alt='Message Filters'></td>
      </tr>
      <tr>
        <td><img src='.github/demos/demo4.png' width='268' alt='Appearance'></td>
        <td><img src='.github/demos/demo5.png' width='268' alt='Chats'></td>
      </tr>
    </table>
  </details>
</h3>

## Downloads

### Windows

#### Official

You can download prebuilt Windows binary from [Releases tab](https://github.com/AyuGram/AyuGramDesktop/releases) or from
the [Telegram channel](https://t.me/AyuGramReleases).

#### Winget

```bash
winget install RadolynLabs.AyuGramDesktop
```

#### Scoop

```bash
scoop bucket add extras
scoop install ayugram
```

#### Self-built

Follow [official guide](https://github.com/AyuGram/AyuGramDesktop/blob/dev/docs/building-win-x64.md) if you want to
build by yourself.

### macOS

#### Official

You can download prebuilt macOS package from [Releases tab](https://github.com/AyuGram/AyuGramDesktop/releases).

#### Homebrew

```bash
brew install --cask ayugram
```

### Arch Linux

#### From source (recommended)

Install `ayugram-desktop` from [AUR](https://aur.archlinux.org/packages/ayugram-desktop).

#### Prebuilt binaries

Install `ayugram-desktop-bin` from [AUR](https://aur.archlinux.org/packages/ayugram-desktop-bin).

Note: these binaries aren't officially maintained by us.

### NixOS

#### Flake (recommended)

Install `ayugram-desktop` from [ndfined-crp/ayugram-desktop](https://github.com/ndfined-crp/ayugram-desktop)

#### Nixpkgs

Install `ayugram-desktop` from [nixpkgs](https://search.nixos.org/packages?channel=unstable&show=ayugram-desktop)

### ALT Linux

[Sisyphus](https://packages.altlinux.org/en/sisyphus/srpms/ayugram-desktop/)

### Gentoo Linux

See [this repository](https://codeberg.org/OverLessArtem/ayugram-ebuild-gentoo) for installation manual.

### Void Linux
See [this repository](https://codeberg.org/OverLessArtem/ayugram-template-void) for installation manual.

### EPM

`epm play ayugram`

### Fedora

From [RPM Fusion](https://admin.rpmfusion.org/pkgdb/package/free/ayugram-desktop/) repository.

```bash
dnf install ayugram-desktop
```

### Any other Linux distro

Flatpak: https://github.com/0FL01/AyuGramDesktop-flatpak

Or follow the [official guide](https://github.com/AyuGram/AyuGramDesktop/blob/dev/docs/building-linux.md).

## Donation

Enjoy using **AyuGram**? Consider sending us a tip!

[Here's available methods.](https://docs.ayugram.one/donate/)

## Credits

### Telegram clients

- [Telegram Desktop](https://github.com/telegramdesktop/tdesktop)
- [Kotatogram](https://github.com/kotatogram/kotatogram-desktop)
- [64Gram](https://github.com/TDesktop-x64/tdesktop)
- [Forkgram](https://github.com/forkgram/tdesktop)

### Libraries used

- [JSON for Modern C++](https://github.com/nlohmann/json)
- [SQLite](https://github.com/sqlite/sqlite)
- [sqlite_orm](https://github.com/fnc12/sqlite_orm)
- [androidx sources](https://github.com/androidx/androidx)

### Icons

- [Solar Icon Set](https://www.figma.com/community/file/1166831539721848736)

### Bots

- [TelegramDB](https://t.me/tgdatabase) for username lookup by ID (until closing free inline mode at 2 April 2026)
