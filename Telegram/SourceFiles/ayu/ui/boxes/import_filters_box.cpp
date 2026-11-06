// This is the source code of AyuGram for Desktop.
//
// We do not and cannot prevent the use of our code,
// but be respectful and credit the original author.
//
// Copyright @Radolyn, 2026
#include "ayu/ui/boxes/import_filters_box.h"

#include "lang_auto.h"
#include "ayu/features/filters/filters_utils.h"
#include "styles/style_giveaway.h"
#include "styles/style_layers.h"
#include "styles/style_settings.h"
#include "ui/rect.h"
#include "ui/rp_widget.h"
#include "ui/layers/generic_box.h"
#include "ui/toast/toast.h"
#include "ui/widgets/buttons.h"
#include "ui/widgets/checkbox.h"
#include "ui/wrap/slide_wrap.h"

#include <QtGui/QClipboard>
#include <QtGui/QGuiApplication>

namespace Ui {

void FillImportFiltersBox(not_null<Ui::GenericBox*> box, bool import) {
	box->setStyle(st::giveawayGiftCodeBox);
	box->setNoContentMargin(true);
	box->setTitle(import ? tr::ayu_FiltersMenuImport() : tr::ayu_FiltersMenuExport());
	box->verticalLayout()->resizeToWidth(box->width());

	const auto container = box->verticalLayout();

	const auto skip = st::settingsSendTypeSkip;
	auto wrap = object_ptr<Ui::VerticalLayout>(container);
	const auto inner = wrap.data();
	container->add(
		object_ptr<Ui::OverrideMargins>(
			container,
			std::move(wrap),
			QMargins(0, skip, 0, skip)));

	const auto group = std::make_shared<RadioenumGroup<bool>>(false);
	inner->add(
		object_ptr<Ui::Radioenum<bool>>(
			inner,
			group,
			false,
			import
				? tr::ayu_FiltersImportClipboard(tr::now)
				: tr::ayu_FiltersExportClipboard(tr::now),
			st::settingsSendType),
		st::settingsSendTypePadding);

	const auto actionButton = box->addButton(
		import ? tr::ayu_FiltersMenuImport() : tr::ayu_FiltersMenuExport(),
		[=]
		{
			if (import) {
				FilterUtils::getInstance().importFromJson(
					QGuiApplication::clipboard()->text().toUtf8());
			} else {
				const auto data = FilterUtils::getInstance().exportFilters();
				QGuiApplication::clipboard()->setText(data);

				Toast::Show(tr::lng_text_copied(tr::now));
			}
			box->closeBox();
		});
	const auto buttonWidth = box->width()
		- rect::m::sum::h(st::giveawayGiftCodeBox.buttonPadding);
	actionButton->widthValue() | rpl::filter([=]
	{
		return (actionButton->widthNoMargins() != buttonWidth);
	}) | rpl::on_next([=]
							  {
								  actionButton->resizeToWidth(buttonWidth);
							  },
							  actionButton->lifetime());

	box->addTopButton(st::boxTitleClose, [=] { box->closeBox(); });
}

} // namespace Ui
